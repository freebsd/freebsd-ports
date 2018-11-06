# $FreeBSD$

PORTNAME=	jstest-gtk
PORTVERSION=	20180710
CATEGORIES=	sysutils

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Simple joystick tester based on Gtk+

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pkgconfig libtool localbase:ldflags
USE_GNOME=	gtkmm30 libsigc++20

INSTALLS_ICONS=	yes

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	jstest-gtk
GL_COMMIT=	62f6e2d7d44620e503149510c428df9e004c9f3b

post-extract:
	@${MKDIR} ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/input.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/input-event-codes.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/joystick.h ${WRKSRC}/src/linux/
	@${CP} -f ${FILESDIR}/types.h ${WRKSRC}/src/linux/

post-patch:
	@${REINPLACE_CMD} -e \
	    's|include_directories(SYSTEM|include_directories("$${CMAKE_CURRENT_SOURCE_DIR}/src" SYSTEM|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
