# $FreeBSD$

PORTNAME=	acltool
DISTVERSIONPREFIX=v
DISTVERSION=	1.16.1
CATEGORIES=	sysutils security

MAINTAINER=	pen@lysator.liu.se
COMMENT=	ACL manipulation utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	READLINE SAMBA
OPTIONS_DEFAULT=READLINE

READLINE_USES=	readline
READLINE_DESC=	Build with GNU Readline for interactive editing

SAMBA_USES=	samba
SAMBA_DESC=	Build with Samba (libsmbclient) for SMB support

READLINE_CONFIGURE_WITH=readline
SAMBA_CONFIGURE_WITH=libsmbclient

USE_GITHUB=	yes
GH_ACCOUNT=	ptrrkssn

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/acltool \
		bin/edac bin/lac \
		bin/sac \
		man/man1/edac.1.gz \
		man/man1/lac.1.gz \
		man/man1/sac.1.gz \
		man/man1/acltool.1.gz

.include <bsd.port.mk>
