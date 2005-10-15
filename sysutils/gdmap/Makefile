# New ports collection makefile for:	gdmap
# Date created:		13 Oct 2005
# Whom:			Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gdmap
PORTVERSION=	0.5.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gdmap

MAINTAINER=	delphus@gmail.com
COMMENT=	Graphical disk map Utility

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=	gdmap.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on FreeBSD < 5.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,<sys/vfs.h>,<sys/statvfs.h>,' \
		${WRKSRC}/src/gui_main.c

.include <bsd.port.post.mk>
