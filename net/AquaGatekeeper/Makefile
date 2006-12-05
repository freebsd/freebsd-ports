# New ports collection makefile for:   AquaGatekeeper
# Date created:        2 November 2003
# Whom:                Eugene Grosbein <eugen@grosbein.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	AquaGatekeeper
PORTVERSION=	1.22
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.svzserv.kemerovo.su/pub/FreeBSD/distfiles.misc/ \
		ftp://www.kuzbass.ru/pub/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eugen@grosbein.pp.ru
COMMENT=	Aqua H323 Gatekeeper and proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}

RESTRICTED=	No commercial redistribution

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
	@for docfile in ${WRKSRC}/Help/*; \
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
BROKEN=		Supported only on 4.x systems and later
.elif ${OSVERSION} >= 500000 && ${ARCH} == "i386"
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.elif ${OSVERSION} >= 600000 && ${ARCH} == "amd64"
LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
.endif

.if ${ARCH} == "amd64"
DISTNAME=	AquaGatekeeper122FreeBSDamd64Build131
.else
DISTNAME=	AquaGatekeeper122FreeBSDBuild445
.endif

.include <bsd.port.post.mk>
