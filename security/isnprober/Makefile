# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	isnprober
PORTVERSION=	1.02
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ubizen.com/tools/ \
		PACKETSTORM/UNIX/scanners

MAINTAINER=	onatan@gmail.com
COMMENT=	PenTest tool for TCP Initial Sequence Numbers research

RUN_DEPENDS=	p5-Net-RawIP>=0:net/p5-Net-RawIP

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	run
NO_BUILD=	yes

SHEBANG_FILES=	isnprober

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
