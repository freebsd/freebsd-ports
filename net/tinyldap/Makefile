# $FreeBSD$

PORTNAME=	tinyldap
PORTVERSION=	0.0.${SNAPSHOT}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.dinoex.de/pub/tinyldap/
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Small LDAP implementation

LICENSE=	GPLv2

BUILD_DEPENDS+=	${LOCALBASE}/lib/libowfat.a:${LIBOWFAT_PORT}

SNAPSHOT=	20170319
USES=		tar:bzip2 gmake ssl
WRKSRC=		${WRKDIR}/${PORTNAME}
CFLAGS+=	-DATTRIBS=512
SBINFILES=	acl addindex bindrequest dumpacls dumpidx idx2ldif parse \
		tinyldap_debug tinyldap_standalone
BINFILES=	ldapclient ldapclient_str md5password mysql2ldif \
		tinyldapdelete
DOCFILES=	ACL FORMAT GETTING.STARTED README README.security RFCs \
		THANKS TODO

LIBOWFAT_PORT?=	devel/libowfat
TINYLDAP_DATA?=	${PREFIX}/tinyldap/data

OPTIONS_DEFINE=	DOCS

post-patch:
	${TOUCH} ${WRKSRC}/alloca.h
	${REINPLACE_CMD} -e "s|\"data\"|\"${TINYLDAP_DATA}\"|" \
		${WRKSRC}/tinyldap.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinyldap ${STAGEDIR}${PREFIX}/libexec/
	${CP} -p ${WRKSRC}/ldapdelete ${WRKSRC}/tinyldapdelete
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for i in ${SBINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin/
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
