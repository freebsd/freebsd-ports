# New ports collection makefile for:	modlogan
# Date created:         06.Sep.2000
# Whom:                 Alexander@Leidinger.net
#
# $FreeBSD$
#

PORTNAME=	modlogan
PORTVERSION=	0.8.13
PORTREVISION=	7
CATEGORIES=	textproc www
MASTER_SITES=	http://jan.kneschke.de/projects/modlogan/download/ \
		http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/distfiles/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A modular log file analysis program

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns \
		gd.4:${PORTSDIR}/graphics/gd \
		pcre.0:${PORTSDIR}/devel/pcre \
		expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
.if defined(WITH_MYSQL)
# To quote the author:
#  It is used by src/processor/telecom/... for a commercial project. The
#  project itself is opensource but not documented.
# Therefore no testing if it works is made in the FreeBSD port.
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif

# Please don't remove the comments, as soon as autoconf/libtool get's
# updated in the ports collection the comments may be removed.
# They serve as a reminder.
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-ltdl-install=no --with-gd=${LOCALBASE}/include \
		--program-transform-name=\'\'
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--with-mysql
.endif
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

MAN1=		modlogan.1
DOC1=		faq.txt glosar manual.txt translations.txt \
		using-plugins.txt writing-plugins.txt

post-patch:
	@${REINPLACE_CMD} -e 's:\@config_path\@:${PREFIX}/etc/modlogan:g' ${WRKSRC}/doc/modlogan.conf-dist.in

#post-configure:
#	${TOUCH} ${WRKSRC}/libltdl/config.status

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/modlogan
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/modlogan/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/modlogan
.for i in footer.ihtml header.ihtml output.tmpl convert_history_to_07x.pl convert_to_055.pl convert_to_060.pl
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/examples/modlogan/${i}
.endfor
.for i in css conf def.conf
	[ -f ${PREFIX}/etc/modlogan/modlogan.${i} ] || ${INSTALL_DATA} ${PREFIX}/etc/modlogan/modlogan.${i}-dist ${PREFIX}/etc/modlogan/modlogan.${i}
.endfor

.include <bsd.port.mk>
