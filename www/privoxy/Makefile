# New ports collection makefile for:	privoxy
# Date created:				21 November 2002
# Whom:					John von Essen
#
# $FreeBSD$
#

PORTNAME=	privoxy
PORTVERSION=	3.0.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ijbswa
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:253

USE_RC_SUBR=	privoxy
SUB_FILES=	pkg-message

MAKEFILE=	GNUmakefile

# privoxy-devel is the development release available at the Privoxy website.
# It's not (yet) part of the FreeBSD ports collection.
CONFLICTS=	privoxy-devel-[0-9]*

MAN1=		privoxy.1

OPTIONS=	FORCE "Allows to optionally bypass blocks" On \
		TOGGLE "Support for remote toggling" On \
		EDITOR "Enable webbased action editor" On \
		DEBUG "Build with debugging symbols" Off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FORCE)
CONFIGURE_ARGS+=	--disable-force
.endif

.if defined(WITHOUT_TOGGLE)
CONFIGURE_ARGS+=	--disable-toggle
.endif

.if defined(WITHOUT_EDITOR)
CONFIGURE_ARGS+=	--disable-editor
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile user\),#\1,' \
	${WRKSRC}/config
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} \
		-e 's,^#\(user-manual\) http://www.privoxy.org/user-manual/,\1 ${PREFIX}/share/doc/privoxy-manual,' \
	${WRKSRC}/config

.endif

pre-configure:
	@cd ${WRKSRC}; ${AUTOHEADER}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/etc/privoxy/templates
	@${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${PREFIX}/etc/privoxy/templates
.for file in config default.action standard.action default.filter trust
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc/privoxy
.endfor
	@${INSTALL_MAN}  ${WRKSRC}/privoxy.1 ${MANPREFIX}/man/man1
#	@${MKDIR} ${PREFIX}/share/examples/privoxy
#	@${INSTALL_DATA} ${WRKSRC}/user.action ${PREFIX}/share/examples/privoxy
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/privoxy-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${PREFIX}/share/doc/privoxy-manual
	${INSTALL_DATA} ${WRKSRC}/doc/webserver/p_doc.css ${PREFIX}/share/doc/privoxy-manual
.endif

post-install:
	${MKDIR} /var/log/privoxy
	${CHOWN} privoxy:privoxy /var/log/privoxy
	${CHMOD} 0750 /var/log/privoxy
	${MKDIR} /var/run/privoxy
	${CHOWN} privoxy:privoxy /var/run/privoxy
	${CHMOD} 0750 /var/run/privoxy
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
