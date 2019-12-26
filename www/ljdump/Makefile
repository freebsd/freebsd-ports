# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ljdump
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://hewgill.com/ljdump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to download LiveJournal entries and comments

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	ZLIB

PORTSCOUT=	skipv:1.5.1	# 1.5.1 is identical to 1.5 + our patches

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	ljdump.py
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/ljdump etc/ljdump.config.sample

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE}, ; \
		s,%%PREFIX%%,${PREFIX},' ${WRKSRC}/ljdump.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ljdump.py ${STAGEDIR}${PREFIX}/bin/ljdump
	${INSTALL_DATA} ${WRKSRC}/ljdump.config.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
