# New ports collection makefile for:   AquaGatekeeper2
# Date created:        11 March 2005
# Whom:                Eugene Grosbein <eugen@grosbein.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	AquaGatekeeper
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.infinetwireless.com/WirelessEq/tmp/software/docs/agk/ \
		ftp://www.kuzbass.ru/pub/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eugen@grosbein.pp.ru
COMMENT=	Aqua H323 Gatekeeper and proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFLICTS=	AquaGatekeeper-1.*
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2${PKGNAMESUFFIX}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}

NO_PACKAGE=	"No commercial redistribution"
NO_CDROM=	"No commercial redistribution"

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/AquaGatekeeper ${PREFIX}/sbin/
	@${INSTALL_SCRIPT} ${FILESDIR}/agk.sh.sample ${PREFIX}/etc/rc.d/
	@${INSTALL_DATA} ${WRKSRC}/Config/AquaGatekeeper.cfg ${PREFIX}/etc/AquaGatekeeper.cfg.sample
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Config/Example.cfg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for docfile in ${WRKSRC}/Help/* ${WRKSRC}/*.rtf; \
		do ${INSTALL_MAN} $$docfile ${DOCSDIR}; \
	done
	@${MKDIR} ${DOCSDIR}/Rus
	@for docfile in ${WRKSRC}/Help.Rus/*; \
		do ${INSTALL_MAN} $$docfile ${DOCSDIR}/Rus; \
	done
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} "s'%%PREFIX%%'${PREFIX}'" < pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Supported only on 4.x systems and later"
.elif ${OSVERSION} >= 500000 && ${ARCH} == "i386"
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

.if ${ARCH} == "amd64"
DISTNAME=	AquaGatekeeper200FreeBSDamd64Build653
.else
DISTNAME=	AquaGatekeeper200FreeBSDBuild653
.endif

.include <bsd.port.post.mk>
