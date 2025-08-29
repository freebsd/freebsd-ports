PORTNAME=	modlogan
PORTVERSION=	0.8.13
PORTREVISION=	20
CATEGORIES=	textproc www
MASTER_SITES=	http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/distfiles/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Modular log file analysis program
WWW=		https://sourceforge.net/projects/modlogan/

LIB_DEPENDS=	libadns.so:dns/adns \
		libgd.so:graphics/gd \
		libpcre.so:devel/pcre \
		libpng16.so:graphics/png \
		libexpat.so:textproc/expat2

DEPRECATED=	dependency devel/pcre is EOL
USES=		cpe gettext libtool

OPTIONS_DEFINE=	DOCS MYSQL

# Please don't remove the comments, as soon as autoconf/libtool get's
# updated in the ports collection the comments may be removed.
# They serve as a reminder.
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--enable-ltdl-install=no --with-gd=${LOCALBASE}/include \
		--program-transform-name=\'\'
MYSQL_CONFIGURE_ON=	--with-mysql
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOC1=		faq.txt glosar manual.txt translations.txt \
		using-plugins.txt writing-plugins.txt

post-patch:
	@${REINPLACE_CMD} -e 's:\@config_path\@:${PREFIX}/etc/modlogan:g' ${WRKSRC}/doc/modlogan.conf-dist.in

#post-configure:
#	${TOUCH} ${WRKSRC}/libltdl/config.status

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/doc/modlogan
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}/${PREFIX}/share/doc/modlogan/${i}
.endfor
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/examples/modlogan
.for i in footer.ihtml header.ihtml output.tmpl convert_history_to_07x.pl convert_to_055.pl convert_to_060.pl
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}/${PREFIX}/share/examples/modlogan/${i}
.endfor

.include <bsd.port.mk>
