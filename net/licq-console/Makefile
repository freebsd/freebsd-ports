# New ports collection makefile for:    console-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	console
PORTVERSION=	${CONSOLE_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	licq@FreeBSD.org

USE_AUTOMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"

post-configure:
	@${PERL5} -pi -e 's|^archive_cmds=.*nostdlib.*|| ; \
		s|^build_libtool_need_lc=.*|build_libtool_need_lc=no|' \
		${WRKSRC}/libtool
post-install:
	@${INSTALL_DATA} ${WRKSRC}/licq_console.conf \
		${PREFIX}/etc/licq_console.conf.sample

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/net/licq/Makefile.inc"
.include <bsd.port.post.mk>
