# New ports collection makefile for:	antivir-milter
# Date created:				21 September 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$

PORTNAME=	antivir-milter
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.antivir.de/freebsd/
DISTNAME=	avfbmlt
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
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if (!exists(/usr/lib/libmilter.a)) && (!exists(${PREFIX}/lib/libmilter.a))
IGNORE=		requires Sendmail 8.12
.endif

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

post-patch:
.for i in etc/avmilter.conf init/rc.avmilter
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e 's|\/etc\/avmilter.conf|${PREFIX}&|g' \
		${WRKSRC}/script/avq
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${WRKDIR}/pkg-message
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/antivirupdater.sh > \
		${WRKDIR}/antivirupdater.sh

do-install:
	@${INSTALL} -d -o daemon -g daemon -m 755 ${PREFIX}/AntiVir
	@${INSTALL} -o daemon -g daemon -m 555 ${WRKSRC}/bin/antivir \
		${PREFIX}/AntiVir/antivir-dist
.if !exists(${PREFIX}/AntiVir/antivir)
	@${INSTALL} -o daemon -g daemon -m 555 ${WRKSRC}/bin/antivir \
		${PREFIX}/AntiVir
.endif
	@${INSTALL} -o daemon -g daemon -m 444 ${WRKSRC}/vdf/antivir.vdf \
		${PREFIX}/AntiVir/antivir.vdf-dist
.if !exists(${PREFIX}/AntiVir/antivir.vdf)
	@${INSTALL} -o daemon -g daemon -m 444 ${WRKSRC}/vdf/antivir.vdf \
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
	@${INSTALL_SCRIPT} ${WRKSRC}/init/rc.avmilter \
		${PREFIX}/etc/rc.d/antivir-milter.sh
	@${INSTALL} -d -o daemon -g daemon -m 700 /var/spool/avmilter
.for i in incoming outgoing rejected
	@${INSTALL} -d -o daemon -g daemon -m 700 /var/spool/avmilter/${i}
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
.for i in avmilter_de.pdf avmilter_en.pdf
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/pgp/antivir.gpg ${DOCSDIR}
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
