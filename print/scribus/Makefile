# ex:ts=8
# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	0.6
CATEGORIES=	print
MASTER_SITES=	http://web2.altmuehlnet.de/fschmid/

MAINTAINER=	ports@geeksrus.net

RUN_DEPENDS=    gs:${PORTSDIR}/print/ghostscript-gnu

USE_QT_VER=	2
USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/share/scribus/libs \
		%%PREFIX%%/share/scribus/plugins

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|docs icons|icons|" \
		${WRKSRC}/scribus/Makefile.in
.endif
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|share/scribus/doc|share/doc/scribus|'

.include <bsd.port.mk>
