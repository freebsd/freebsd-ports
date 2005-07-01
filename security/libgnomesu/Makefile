# New ports collection makefile for:	libgnomesu
# Date created:				12 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomesu
PORTVERSION=	1.0.0
CATEGORIES=	security gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/libgnomesu/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Library and frontend for running commands as root

USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
CONFIGURE_ARGS+=--disable-install-pam
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

CONFLICTS=	gnomesu-[0-9]*

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/gnomesu-pam.4.x.sample ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/gnomesu-pam.5.x.sample ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/api.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libgnomesu.css ${DOCSDIR}
.endif
	@${SED} -e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
