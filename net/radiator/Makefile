# New ports collection makefile for:	radiator
# Date created:				05 March 2003
# Whom:					shan
#
# $FreeBSD$
#

PORTNAME=	Radiator
PORTVERSION=	4.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# fetch manually
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Radiator Radius Server by Open System Consultants

OPTIONS=	MYSQL "MySQL Support" off

PERL_CONFIGURE=	yes

RESTRICTED=	"Commercial software"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
BUILD_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=		will not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the UNIX version after\
		purchasing the license at: http://www.open.com.au/ \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR}/${DIST_SUBDIR} and then restart this build. \
		(optionally download patches-${PORTVERSION}.tar.gz to the \
		same directory as well)
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

pre-configure:
.if exists(${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz)
	${TAR} -xvzf ${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz -C ${WRKSRC}
.endif

.include <bsd.port.post.mk>
