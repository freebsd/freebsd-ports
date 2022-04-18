PORTNAME=	sshout
DISTVERSION=	1.2.0
PORTREVISION=	1
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

OPTIONS_DEFINE=		NLS IRC
OPTIONS_DEFAULT=	NLS
OPTIONS_GROUP=		SUGGESTED
OPTIONS_GROUP_SUGGESTED=XCLIP ELINKS

SUGGESTED_DESC=		Suggested ports

XCLIP_DESC=		Add dependency to xclip(1) for CLI pasteimage support
XCLIP_RUN_DEPENDS=	xclip:x11/xclip
ELINKS_DESC=		Add dependency to elinks(1) for showing HTML messages in CLI
ELINKS_RUN_DEPENDS=	elinks>=0.12:www/elinks

NLS_USES=		gettext
NLS_MAKE_ENV=		NLS_LIBS="-l intl"
NLS_MAKE_ENV_OFF=	NO_NLS=1

IRC_DESC=		Experimental IRC over SSH frontend
IRC_CPPFLAGS=		-D ENABLE_IRC_FRONTEND=1

OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.include <bsd.port.mk>
