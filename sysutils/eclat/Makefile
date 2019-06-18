# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eclat
PORTVERSION=	2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	EC2 command line administration tool

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

USES=		localbase tar:xz
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS GDBM LDAP
OPTIONS_DEFAULT=	GDBM

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
