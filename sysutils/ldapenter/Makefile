# Created by: rflynn@acsalaska.net
# $FreeBSD$

PORTNAME=	ldapenter
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils editors net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add/Modify LDAP entries using template forms

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Unfetchable (google code has gone away)

MAKEFILE=	BSDmakefile
USES=		tar:bzip2 uidfix
USE_OPENLDAP=	24
LDFLAGS+=	-L${LOCALBASE}/lib -llber

PLIST_FILES=	bin/ldapform \
		bin/ldapedit \
		man/man1/ldapform.1.gz \
		man/man1/ldapedit.1.gz

.include <bsd.port.mk>
