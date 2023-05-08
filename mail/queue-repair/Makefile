PORTNAME=	queue-repair
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/${PORTNAME}/

MAINTAINER=	jeff.jschmidt@gmail.com
COMMENT=	Qmail queue diagnostic and repair tool
WWW=		http://pyropus.ca/software/queue-repair/

LICENSE=	GPLv2

USES=		python shebangfix
SHEBANG_FILES=	queue_repair.py

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		DOCS QMAIL_PORT
OPTIONS_DEFAULT=	QMAIL_PORT
QMAIL_PORT_DESC=	Depend on qmail port

QMAIL_PORT_USES=	qmail:run

PLIST_FILES=	bin/queue-repair
PORTDOCS=	BLURB CHANGELOG TODO

do-configure-QMAIL_PORT-on:
	${REINPLACE_CMD} -e 's,nofiles,qnofiles,' ${WRKSRC}/queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${STAGEDIR}${PREFIX}/bin/queue-repair

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
