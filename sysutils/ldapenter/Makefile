# Created by: rflynn@acsalaska.net
# $FreeBSD$

PORTNAME=	ldapenter
PORTVERSION=	0.2.0
CATEGORIES=	sysutils editors net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add/Modify LDAP entries using template forms

LICENSE=	BSD

MAKEFILE=	BSDmakefile
USE_BZIP2=	yes
USE_OPENLDAP=	24

MANCOMPRESSED=	yes
MAN1=		ldapform.1 ldapedit.1

PLIST_FILES=	bin/ldapform \
		bin/ldapedit

.include <bsd.port.mk>
