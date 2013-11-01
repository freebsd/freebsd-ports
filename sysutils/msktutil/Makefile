# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msktutil
PORTVERSION=	0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
    		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Utility to manage Active Directory interoperability

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
WANT_OPENLDAP_SASL=	yes

CONFIGURE_ARGS+=--with-sasldir=${PREFIX}

MAN1=		msktutil.1
PLIST_FILES=	sbin/msktutil

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900035
LDFLAGS+=	-lgssapi_krb5
.endif

.if ${OSVERSION} < 800000
BROKEN=		does not build on FreeBSD 7.x
.endif

.include <bsd.port.post.mk>
