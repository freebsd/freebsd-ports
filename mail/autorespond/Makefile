PORTNAME=	autorespond
PORTVERSION=	2.0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

PATCH_SITES=	http://people.FreeBSD.org/~roam/ports/patches/mail/
PATCHFILES=	${DISTNAME}-conf-strcasestr.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple autoresponder for qmail

PLIST_FILES=	bin/autorespond man/man1/autorespond.1.gz

.if defined(WITHOUT_MDOC_MANPAGE)
AR_MANPAGE=	${WRKSRC}/autorespond.1
.else
AR_MANPAGE=	${FILESDIR}/autorespond.1
.endif

post-patch:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld
	${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${AR_MANPAGE} ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
