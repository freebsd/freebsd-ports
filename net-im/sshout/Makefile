PORTNAME=	sshout
DISTVERSION=	1.3.0
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	whr@rivoreo.one
COMMENT=	Instant-messaging service based on SSH
WWW=		https://sourceforge.net/projects/sshout/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmhash.so:security/mhash

USES=		gmake iconv readline tar:bz2
USE_RC_SUBR=	${PORTNAME}

MAKE_ENV=	ICONV_LIBS="${ICONV_LIB}" \
		LIBEXECDIR=${PREFIX}/libexec \
		MANDIR=${PREFIX}/share/man

NO_WRKSUBDIR=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=		IRC NLS
OPTIONS_DEFAULT=	NLS
OPTIONS_GROUP=		SUGGESTED
OPTIONS_GROUP_SUGGESTED=XCLIP ELINKS

OPTIONS_SUB=		yes

ELINKS_DESC=		Add dependency to elinks(1) for showing HTML messages in CLI
IRC_DESC=		Experimental IRC over SSH frontend
SUGGESTED_DESC=		Suggested ports
XCLIP_DESC=		Add dependency to xclip(1) for CLI pasteimage support

ELINKS_RUN_DEPENDS=	elinks>=0.12:www/elinks

IRC_CPPFLAGS=		-D ENABLE_IRC_FRONTEND=1

NLS_USES=		gettext
NLS_MAKE_ENV=		NLS_LIBS="-l intl"
NLS_MAKE_ENV_OFF=	NO_NLS=1

XCLIP_RUN_DEPENDS=	xclip:x11/xclip

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/sshoutd \
		${STAGEDIR}${PREFIX}/sbin/sshoutcfg

.include <bsd.port.mk>
