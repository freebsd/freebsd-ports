# New ports collection makefile for:	jwhois
# Date created:		15 Jul 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	jwhois
PORTVERSION=	3.2.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	jwhois

MAINTAINER=	matusita@FreeBSD.org
COMMENT=An improved WHOIS client capable of selecting server to query

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var/jwhois
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB=	NLS=""
.endif

INSTALL_TARGET=	install-strip

MANLANG=	"" sv
MAN1=	jwhois.1
INFO=	jwhois

.include <bsd.port.pre.mk>

.if exists(${FILESDIR}/jwhois.conf)
JWHOIS_CONF_SRC=${FILESDIR}/jwhois.conf
.else
JWHOIS_CONF_SRC=${WRKSRC}/example/jwhois.conf
.endif

post-install:
	${MKDIR} ${PREFIX}/var/jwhois
	${CHOWN} :nogroup ${PREFIX}/var/jwhois
	${CHMOD} g+w ${PREFIX}/var/jwhois
	${CHOWN} :nogroup ${PREFIX}/bin/jwhois
	${CHMOD} g+s ${PREFIX}/bin/jwhois
	${INSTALL_DATA} ${JWHOIS_CONF_SRC} ${PREFIX}/etc/jwhois.conf.sample
	if [ ! -f ${PREFIX}/etc/jwhois.conf ]; then ${INSTALL_DATA} ${PREFIX}/etc/jwhois.conf.sample ${PREFIX}/etc/jwhois.conf; fi

.include <bsd.port.post.mk>
