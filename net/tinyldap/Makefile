# $FreeBSD$

PORTNAME=	tinyldap
PORTVERSION=	0.0.${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.dinoex.de/pub/tinyldap/
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A small LDAP implementation

BUILD_DEPENDS+=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/${LIBOWFAT_PORT}

LICENSE=	GPLv2

SNAPSHOT=	20091122
USE_BZIP2=	yes
USE_GMAKE=	yes
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

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
