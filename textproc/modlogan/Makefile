# New ports collection makefile for:	modlogan
# Date created:         06.Sep.2000
# Whom:                 Alexander@Leidinger.net
#
# $FreeBSD$
#

PORTNAME=	modlogan
PORTVERSION=	0.7.12
CATEGORIES=	textproc www
MASTER_SITES=	http://jan.kneschke.de/projects/modlogan/download/ \
		${MASTER_SITE_SOURCEFORGE}

MAINTAINER=	Alexander@Leidinger.net

LIB_DEPENDS=	adns.1:${PORTSDIR}/net/adns \
		gd.2:${PORTSDIR}/graphics/gd \
		intl.1:${PORTSDIR}/devel/gettext \
		pcre.0:${PORTSDIR}/devel/pcre \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		ltdl.1:${PORTSDIR}/devel/libtool

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
#USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
#LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-ltdl-install=no --with-gd=${LOCALBASE}/include
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--with-mysql
.endif
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

MAN1=		modlogan.1
DOC1=		faq.txt glosar manual.txt translations.txt \
		using-plugins.txt writing-plugins.txt

post-patch:
	@${PERL} -pi -e 's:\@config_path\@:${PREFIX}/etc/modlogan:g' ${WRKSRC}/doc/modlogan.conf-dist.in

post-configure:
	${TOUCH} ${WRKSRC}/libltdl/config.status

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
	@# remove .la (can't use USE_LIBTOOL)
	-${RM} ${PREFIX}/lib/libmla_*.la
	${MV} ${PREFIX}/bin/${MACHINE_ARCH}--freebsd${OSREL}-modlogan ${PREFIX}/bin/modlogan
	${MV} ${PREFIX}/man/man1/${MACHINE_ARCH}--freebsd${OSREL}-modlogan.1 ${PREFIX}/man/man1/modlogan.1
.for i in css conf def.conf
	[ -f ${PREFIX}/etc/modlogan/modlogan.${i} ] || ${INSTALL_DATA} ${PREFIX}/etc/modlogan/modlogan.${i}-dist ${PREFIX}/etc/modlogan/modlogan.${i}
.endfor

.include <bsd.port.mk>
