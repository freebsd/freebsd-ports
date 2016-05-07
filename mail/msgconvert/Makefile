# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	msgconvert
PORTVERSION=	20060330
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.webonaut.com/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_SUFX=	.bz2

MAINTAINER=	klammer@webonaut.com
COMMENT=	Convert .MSG files to multipart MIME messages (mbox)

RUN_DEPENDS=	p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-TimeDate>=0:devel/p5-TimeDate

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USES=		shebangfix perl5

EXTRACT_CMD=	${BZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.pl

PLIST_FILES=	bin/msgconvert.pl bin/msgconvert
SHEBANG_FILES=	${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}.pl
	${LN} -s ${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
