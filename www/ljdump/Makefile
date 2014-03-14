# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ljdump
PORTVERSION=	1.5
CATEGORIES=	www python
MASTER_SITES=	http://hewgill.com/ljdump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to download LiveJournal entries and comments

PORTSCOUT=	skipv:1.5.1	# 1.5.1 is identical to 1.5 + our patches

NO_BUILD=	yes
USE_PYTHON_RUN=	yes

PLIST_FILES=	bin/ljdump etc/ljdump.config.sample

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE}, ; \
		s,%%PREFIX%%,${PREFIX},' ${WRKSRC}/ljdump.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ljdump.py ${STAGEDIR}${PREFIX}/bin/ljdump
	${INSTALL_DATA} ${WRKSRC}/ljdump.config.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
