# New ports collection makefile for:	wtmp-tools
# Date created:				3 October 2005
# Whom:					Oleg M. Golovanov <olmi@rentech.ru>
#
# $FreeBSD$
#

PORTNAME=	wtmp-tools
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rentech.ru/archives/wtmp-tools/

MAINTAINER=	master@rentech.ru
COMMENT=	The tool for editing wtmp files and converting into this format

MAN1=		t2w.1
MANCOMPRESSED=	yes

PORTDOCS=	*
PLIST_FILES=	bin/t2w

post-patch:
	@${REINPLACE_CMD} -e 's,^prefix.*=.*$$,prefix = ${PREFIX},' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
