# $FreeBSD$

PORTNAME=	sshout
DISTVERSION=	1.1.1
CATEGORIES=	net-im
MASTER_SITES=	SF/sshout/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	msl0000023508@gmail.com
COMMENT=	Instant-messaging service based on SSH

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmhash.so:security/mhash

USES=		tar:bz2 gmake readline

NO_WRKSUBDIR=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	LIBEXECDIR=\${PREFIX}/libexec \
		MANDIR=\${PREFIX}/man

USE_RC_SUBR=	sshout

USERS=		sshout
GROUPS=		sshout

PLIST_FILES=	libexec/sshoutd \
		man/man8/sshoutcfg.8.gz \
		sbin/sshoutcfg

OPTIONS_DEFINE=	IRC
IRC_DESC=	Enable the experimental IRC over SSH frontend
IRC_CPPFLAGS=	-DENABLE_IRC_FRONTEND

.include <bsd.port.mk>
