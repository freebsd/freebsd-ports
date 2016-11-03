# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	integrit
PORTVERSION=	4.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File integrity verification program

USES=		makeinfo
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME} utils

PLIST_FILES=	bin/i-ls sbin/i-viewdb sbin/integrit man/man1/i-ls.1.gz \
		man/man1/i-viewdb.1.gz man/man1/integrit.1.gz
INFO=		integrit

post-patch:
	@${REINPLACE_CMD} -E 's,[\({](infodir|MANDIR)[\)}],(DESTDIR)$$&,' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -E 's,(BIN|SBIN)DIR),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/utils/Makefile.in
	@${ECHO_CMD} ".PHONY: utils" >> ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
