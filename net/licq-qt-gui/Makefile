# New ports collection makefile for:    qt-gui-licq
# Date created:                         18 October 2000
# Whom:                                 Jeremy Norris <ishmael272home.com>
#
# $FreeBSD$
#

PORTNAME=	qt-gui
PORTVERSION=	${QT_LICQ_VER}
CATEGORIES=	net

MAINTAINER=	dinoex@FreeBSD.org

USE_AUTOMAKE=	yes
USE_QT_VER=	2

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}"

post-patch:
	@${PERL5} -pi -e 's|libqt-mt.so.2|libqt2-mt.so.4|g;' \
		-e 's|-lqt-mt|-lqt2-mt|g;' -e 's|libqt.so|libqt2.so|g;' \
		-e 's|-lqt$$|-lqt2|g;' ${WRKSRC}/acinclude.m4

pre-configure:
	@(cd ${WRKSRC} && ${ACLOCAL})

post-configure:
	@(cd ${WRKSRC} && ${PERL5} am_edit)
	@${PERL5} -pi -e 's|^archive_cmds=.*nostdlib.*|| ; \
		s|^build_libtool_need_lc=.*|build_libtool_need_lc=no| ; \
		s|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
	${RM} -rf ${PREFIX}/share/licq/qt-gui/locale

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/net/licq/Makefile.inc"
.include <bsd.port.post.mk>
