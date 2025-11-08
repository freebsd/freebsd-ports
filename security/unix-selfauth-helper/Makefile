PORTNAME=	unix-selfauth-helper
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${WWW}/releases/download/v${DISTVERSION}/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Local self-authentication for pam_exec
WWW=		https://github.com/Zirias/${PORTNAME}

LICENSE=	BSD2CLAUSE

USES=		tar:xz

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man

PLIST_FILES=	etc/pam.d/unix-selfauth \
		libexec/unix-selfauth-helper \
		share/man/man8/unix-selfauth-helper.8.gz

.include <bsd.port.mk>
