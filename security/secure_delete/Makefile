PORTNAME=	secure_delete
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/groups/thc \
		http://freeworld.thc.org/releases/

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	Secure data deletion toolkit
WWW=		https://www.thc.org/

LICENSE=	GPLv2 # mentioned in manpages

CONFLICTS=	srm

MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES FILES README secure_delete.doc usenix6-gutmann.doc
PLIST_FILES=	bin/sdel bin/sfill bin/smem bin/srm bin/sswap \
		bin/the_cleaner.sh share/man/man1/sfill.1.gz \
		share/man/man1/smem.1.gz \
		share/man/man1/srm.1.gz share/man/man1/sswap.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|-O2 |$$(CFLAGS) | ;\
		 /strip/s|^|#|' ${WRKSRC}/Makefile

do-install:
.for i in srm sfill sswap smem
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${i}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/the_cleaner.sh ${STAGEDIR}${PREFIX}/bin
	${LN} -sf srm ${STAGEDIR}${PREFIX}/bin/sdel

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
