# New ports collection makefile for:	radiator
# Date created:				05 March 2003
# Whom:					shan
#
# $FreeBSD$
#

PORTNAME=	Radiator
PORTVERSION=	3.11
CATEGORIES=	net
MASTER_SITES=	# fetch manually
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	shanali@yahoo.com
COMMENT=	Radiator Radius Server by Open System Consultants

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

RESTRICTED=	"Commercial software"

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=		will not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the UNIX version after\
		purchasing the license at: http://www.open.com.au/ \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR}/${DIST_SUBDIR} and then restart this build. \
		(optionally download patches-${PORTVERSION}.tar.gz to the \
		same directory as well)
.endif

pre-configure:
.if exists(${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz)
	${TAR} -xvzf ${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz -C ${WRKSRC}
.endif

.include <bsd.port.post.mk>
