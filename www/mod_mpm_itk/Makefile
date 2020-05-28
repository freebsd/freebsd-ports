# Created by: Lukasz Wasikowski <lukasz@wasikowski.net>
# $FreeBSD$

PORTNAME=	mod_mpm_itk
PORTVERSION=	2.4.7
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://mpm-itk.sesse.net/ \
		http://lukasz.wasikowski.net/files/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	mpm-itk-2.4.7-04

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	Run each vhost under a separate uid and gid

LICENSE=	APACHE20

USES=		apache:2.4
GNU_CONFIGURE=	yes

AP_FAST_BUILD=	yes
SRC_FILE=	*.c

SUB_FILES+=	${APMOD_FILE}.sample
APMOD_FILE=	200_${PORTNAME}.conf
SUB_LIST+=	APMOD_FILE=${APMOD_FILE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE}.sample ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

.include <bsd.port.mk>
