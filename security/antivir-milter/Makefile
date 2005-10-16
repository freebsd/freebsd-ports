# New ports collection makefile for:	antivir-milter
# Date created:				21 September 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$

PORTNAME=	antivir-milter
PORTVERSION=	1.1.0p7
DISTVERSIONPREFIX=	prof-
DISTVERSION=	${PORTVERSION:C/p/-/}
CATEGORIES=	security mail
MASTER_SITES=	http://dl.antivir.de/down/unix/packages/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	AntiVir Milter mail virusscanner for Sendmail

RESTRICTED=	H+BEDV Datentechnik GmbH forbids any redistribution
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_REINPLACE=	yes
# Auto re-fetch sucks!
FETCH_CMD=	/usr/bin/fetch -A
# When the avmilter binary is stripped its self-check fails.
STRIP=
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
IGNORE=		requires FreeBSD 4.0 or higher
.endif

.if (!exists(/usr/lib/libmilter.a)) && (!exists(${LOCALBASE}/lib/libmilter.a))
IGNORE=		requires Sendmail 8.12
.endif

.if ${OSVERSION} >= 503001
BINSRC=		${WRKSRC}/bin/freebsd5
.if ${OSVERSION} > 600004
LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
.endif
.else
BINSRC=		${WRKSRC}/bin/freebsd
.endif

post-extract:
	@${CP} ${FILESDIR}/avq.sh ${WRKSRC}/script/avq
	@${MV} ${WRKSRC}/templates/en/patho-admnistrator\
		${WRKSRC}/templates/en/patho-administrator
	@${MV} ${WRKSRC}/templates/en/virus-admnistrator\
		${WRKSRC}/templates/en/virus-administrator

post-patch:
.for i in doc/MANUAL etc/antivir.conf etc/avmilter.conf init/rc.avmilter \
	pgp/README script/avq script/avupdater
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
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755 ${BINSRC}/antivir \
		${PREFIX}/AntiVir/antivir-dist_avmilter
.if !exists(${PREFIX}/AntiVir/antivir)
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 755 ${BINSRC}/antivir \
		${PREFIX}/AntiVir
.endif
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 644 ${WRKSRC}/vdf/antivir.vdf \
		${PREFIX}/AntiVir/antivir.vdf-dist_avmilter
.if !exists(${PREFIX}/AntiVir/antivir.vdf)
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 644 ${WRKSRC}/vdf/antivir.vdf \
		${PREFIX}/AntiVir
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/script/avq ${PREFIX}/bin
	@${INSTALL} -d ${PREFIX}/etc/avmilter
.for i in avmilter.conf avmilter.ignore avmilter.scan avmilter.warn
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc/avmilter/${i}.sample
.if !exists(${PREFIX}/etc/avmilter/${i})
	@${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc/avmilter
.endif
.endfor
	@${INSTALL_DATA} ${WRKSRC}/etc/antivir.conf \
		${PREFIX}/etc/antivir.conf.sample
.if !exists(${PREFIX}/etc/antivir.conf)
	@${INSTALL_DATA} ${WRKSRC}/etc/antivir.conf ${PREFIX}/etc
.endif
	@${LN} -sf ${PREFIX}/etc/antivir.conf /etc
	@${INSTALL_PROGRAM} ${BINSRC}/avmilter ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKDIR}/antivirupdater.sh \
		${PREFIX}/sbin/antivirupdater
	@${INSTALL_SCRIPT} ${WRKDIR}/avqrm.sh ${PREFIX}/bin/avqrm
	@${INSTALL_SCRIPT} ${WRKSRC}/init/rc.avmilter \
		${PREFIX}/etc/rc.d/avmilter.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/script/avupdater \
		${PREFIX}/etc/rc.d/avupdater.sh-dist_avmilter
	@${INSTALL} -d -o smmsp -g smmsp -m 700 /var/spool/avmilter
.for i in incoming outgoing rejected
	@${INSTALL} -d -o smmsp -g smmsp -m 700 /var/spool/avmilter/${i}
.endfor
	@${INSTALL} -d ${EXAMPLESDIR}
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
.for i in MANUAL avmilter_de.pdf avmilter_en.pdf
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/pgp/README ${DOCSDIR}/README.gpg
	@${INSTALL_DATA} ${WRKSRC}/pgp/antivir.gpg ${DOCSDIR}
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
