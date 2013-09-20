# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	xsu
PORTVERSION=	0.2.4
PORTREVISION=	6
CATEGORIES=	sysutils gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xsu runs commands as root after prompting for the root password

GNU_CONFIGURE=	yes
USES=        pathfix
USE_GNOME=	gnomeprefix gnomelibs
CONFIGURE_ARGS=	--su-pwd-out="Password:"
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN8=	xsu.8

DOCS=	CHANGELOG COPYING INSTALL

NO_STAGE=	yes
post-patch:
.ifdef NOPORTDOCS
	${REINPLACE_CMD} -e '/doc_path\/$$name/s,^[[:blank:]],#&,' \
		-e '/@echo "Now read the README file"/s,^[[:blank:]],#&,' \
		${WRKSRC}/configure
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/xsu.desktop \
		${PREFIX}/share/gnome/apps/System
.if !defined(NOPORTDOCS)
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
