# New ports collection makefile for:	antivir-milter
# Date created:				21 September 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$

PORTNAME=	antivir-milter
PORTVERSION=	1.1.b
PORTREVISION=	2
CATEGORIES=	security mail
#MASTER_SITES=	ftp://ftp.antivir.de/freebsd/ \
#		http://www.antivir.de/dateien/antivir/release/
MASTER_SITES=	http://www.antivir.de/dateien/antivir/beta/freebsd/
#DISTNAME=	avfbmlt
DISTNAME=	avfbmlt_beta
EXTRACT_SUFX=	.tgz

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	AntiVir Milter mail virusscanner for Sendmail

RESTRICTED=	H+BEDV Datentechnik GmbH forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_REINPLACE=	yes
# Auto re-fetch sucks!
FETCH_CMD=	/usr/bin/fetch -A
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.b/-beta/}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if (!exists(/usr/lib/libmilter.a)) && (!exists(${LOCALBASE}/lib/libmilter.a))
IGNORE=		requires Sendmail 8.12
.endif

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

post-patch:
.for i in doc/MANUAL etc/antivir.conf etc/avmilter.conf init/rc.avmilter \
	script/avq
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${WRKDIR}/pkg-message
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/antivirupdater.sh > \
		${WRKDIR}/antivirupdater.sh
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/avqrm.sh > \
		${WRKDIR}/avqrm.sh

do-install:
	@${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755 ${PREFIX}/AntiVir
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755 ${WRKSRC}/bin/antivir \
		${PREFIX}/AntiVir/antivir-dist_avfbmlt
.if !exists(${PREFIX}/AntiVir/antivir)
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755 ${WRKSRC}/bin/antivir \
		${PREFIX}/AntiVir
.endif
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 644 ${WRKSRC}/vdf/antivir.vdf \
		${PREFIX}/AntiVir/antivir.vdf-dist_avfbmlt
.if !exists(${PREFIX}/AntiVir/antivir.vdf)
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 644 ${WRKSRC}/vdf/antivir.vdf \
		${PREFIX}/AntiVir
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/script/avq ${PREFIX}/bin
.for i in antivir.conf avmilter.conf
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc/${i}.sample
.if !exists(${PREFIX}/etc/${i})
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc
.endif
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/avmilter ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKDIR}/antivirupdater.sh \
		${PREFIX}/sbin/antivirupdater
	@${INSTALL_SCRIPT} ${WRKDIR}/avqrm.sh ${PREFIX}/bin/avqrm
	@${INSTALL_SCRIPT} ${WRKSRC}/init/rc.avmilter \
		${PREFIX}/etc/rc.d/antivir-milter.sh
	@${INSTALL} -d -o smmsp -g smmsp -m 700 /var/spool/avmilter
.for i in incoming outgoing rejected
	@${INSTALL} -d -o smmsp -g smmsp -m 700 /var/spool/avmilter/${i}
.endfor
	@${INSTALL} -d ${EXAMPLESDIR}
.for i in avmilter.ignore avmilter.scan avmilter.warn
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${EXAMPLESDIR}
.endfor
.for i in de en es hu it nl
	@${INSTALL} -d ${EXAMPLESDIR}/templates/${i}
.for j in patho-administrator patho-recipient patho-sender virus-administrator \
	virus-recipient virus-sender
	@${INSTALL_DATA} ${WRKSRC}/templates/${i}/${j} \
		${EXAMPLESDIR}/templates/${i}
.endfor
.endfor
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
.for i in ChangeLog LICENSE LICENSE.DE
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/MANUAL ${DOCSDIR}
.for i in avmilter_de.pdf avmilter_en.pdf
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/pgp/antivir.gpg ${DOCSDIR}
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
