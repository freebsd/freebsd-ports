# New ports collection makefile for:	FreeBSD Update Client
# Date created:				21 March 2003
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-update
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.daemonology.net/freebsd-update/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Fetches and installs binary updates to FreeBSD

RUN_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff
# This is a critical security port.  If it breaks, Bad Things will happen.
# Under no circumstances should this port ever be modified without approval
# from the maintainer or security-officer, even for "cosmetic" fixes.

# The RSA code has been tested and works on these platforms.  On other
# platforms, it either doesn't work or hasn't been tested.
ONLY_FOR_ARCHS=	i386 amd64 alpha sparc64

MAN5=		freebsd-update.conf.5
MAN8=		freebsd-update.8
PLIST_FILES=	sbin/freebsd-update		\
		sbin/freebsd-update-verify	\
		etc/freebsd-update.conf.sample
PLIST_DIRS=	freebsd-update

PKGMESSAGE=	${WRKDIR}/pkg-message

.ifdef NOPORTDOCS
MAKE_ENV+=	NODOCS=yes
.else
PORTDOCS=	LICENSE README VERSION
.endif

post-extract:
	${SED} -e "s#PREFIX=/usr/local#PREFIX=${PREFIX}#g" \
		${WRKSRC}/freebsd-update > ${WRKSRC}/freebsd-update.new
	${MV} ${WRKSRC}/freebsd-update.new ${WRKSRC}/freebsd-update
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/pkg-message \
		> ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
