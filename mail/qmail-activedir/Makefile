PORTNAME=	qmail-activedir
PORTVERSION=	0.17
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://fo2k.com/qmail-activedir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to allow qmail to authenticate users through a MS ad

USES=		qmail:run
SUB_FILES=	pkg-message
SUB_LIST+=	QMAIL_PREFIX=${QMAIL_PREFIX}
USE_OPENLDAP=	yes

BINARIES=	checkadpassword qmail-adgetpw create_alias_files

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wall -lldap

.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/var/qmail,${QMAIL_PREFIX},g' \
			  -e 's,\(#define AD_USE_GC\) 1,\1 0,' \
			  -e 's,\(#define AD_ONLY_USE_SSL\) 1,\1 0,' \
		${WRKSRC}/ad_func.h

do-build:
.for prog in ${BINARIES}
	${CC} ${CFLAGS} ${WRKSRC}/${prog}.c ${WRKSRC}/ad_func.c -o \
		${WRKSRC}/${prog}
.endfor

do-install:
.for prog in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${STAGEDIR}${PREFIX}/bin/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
