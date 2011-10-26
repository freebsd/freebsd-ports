# New ports collection makefile for:   AquaGatekeeper
# Date created:        2 November 2003
# Whom:                Eugene Grosbein <eugen@grosbein.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	AquaGatekeeper
PORTVERSION=	1.22
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.grosbein.net/freebsd/AquaGatekeeper/ \
		ftp://www.kuzbass.ru/pub/FreeBSD/ports/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@grosbein.pp.ru
COMMENT=	Aqua H323 Gatekeeper and proxy

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFLICTS=	AquaGatekeeper-2.*
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
DISTINFO_FILE=	${MASTERDIR}/distinfo.${ARCH}

RESTRICTED=	No commercial redistribution
SUB_FILES=	pkg-message
STRIP=
STRIP_CMD=	${TRUE}
DEPRECATED=	Binary port of software abandoned by the vendor

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

# This is binary port of closed-source software
.if ${ARCH} == "i386"
DISTNAME=	AquaGatekeeper122FreeBSDBuild445
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x \
		crypto.3:${PORTSDIR}/misc/compat5x
.elif ${ARCH} == "amd64"
DISTNAME=	AquaGatekeeper122FreeBSDamd64Build131
LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x
.endif

.include <bsd.port.post.mk>
