# New ports collection makefile for:	wmmemload
# Date created:				14 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmemload
PORTVERSION=	0.1.3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.markstaggs.net/wmmemload/

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes

MAN1=		wmmemload.1

pre-patch:
.for dir in src doc .
	@${PERL} -pi -e 's|\@program_transform_name\@||' \
		${WRKSRC}/${dir}/Makefile.in
.endfor
	@${RM} ${WRKSRC}/src/*.o

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
