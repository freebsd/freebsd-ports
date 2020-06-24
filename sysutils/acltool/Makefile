# $FreeBSD$

PORTNAME=		acltool
DISTVERSIONPREFIX=	v
DISTVERSION=		1.16.2
CATEGORIES=		sysutils security

MAINTAINER=		pen@lysator.liu.se
COMMENT=		ACL manipulation tool

LICENSE=		BSD3CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

OPTIONS_DEFINE=		SAMBA

OPTIONS_RADIO=		LINE_EDITOR
OPTIONS_RADIO_LINE_EDITOR=	READLINE LIBEDIT
OPTIONS_DEFAULT=	READLINE

SAMBA_USES=		samba
SAMBA_DESC=		Build with Samba (libsmbclient) for SMB support

READLINE_USES=		readline
READLINE_DESC=		Build with GNU Readline for interactive editing

LIBEDIT_USES=		libedit
LIBEDIT_DESC=		Build with BSD Libedit for interactive editing

SAMBA_CONFIGURE_WITH=	libsmbclient
READLINE_CONFIGURE_WITH=	readline
LIBEDIT_CONFIGURE_WITH=	libedit

USE_GITHUB=		yes
GH_ACCOUNT=		ptrrkssn

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip

.include <bsd.port.mk>
