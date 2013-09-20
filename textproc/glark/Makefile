# Created by: ijliao
# $FreeBSD$

PORTNAME=	glark
PORTVERSION=	1.8.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.incava.org/pub/glark/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Search text files for complex regular expressions

USE_RUBY=	yes
NO_BUILD=	yes

MAN1=		glark.1
PLIST_FILES=	bin/glark \
		share/glark/env.rb \
		share/glark/extensions.rb \
		share/glark/filetest.rb \
		share/glark/glark.rb \
		share/glark/help.rb \
		share/glark/io.rb \
		share/glark/log.rb \
		share/glark/options.rb \
		share/glark/optproc.rb \
		share/glark/regexp.rb \
		share/glark/text.rb
PLIST_DIRS=	share/glark

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/glark ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/glark/* ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/glark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
