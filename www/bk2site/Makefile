# ex:ts=8
# Ports collection makefile for:  bk2site
# Date created:                   Wed Dec 06, 2000
# Whom:                           clive
#
# $FreeBSD$
#

PORTNAME=	bk2site
PORTVERSION=	1.1.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clive@FreeBSD.org

.include <bsd.port.pre.mk>
APXS=		${LOCALBASE}/sbin/apxs
.if exists(${APXS})
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin/${PORTNAME}
ICONSDIR?=	www/icons/${PORTNAME}
.endif

.else # No apache installed.
CGIDIR?=	share/${PORTNAME}
ICONSDIR?=	share/${PORTNAME}
.endif

MAN1=		bk2site.1
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --enable-standard-datadir

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}"

post-patch:
	@${PERL} -pi -e 's,/etc/bk2site,${PREFIX}/etc/bk2site,' \
	${WRKSRC}/dot.bk2siterc ${WRKSRC}/search.pl ${WRKSRC}/bk2site.1 \
	${WRKSRC}/bk2site.html
	@${PERL} -pi -e 's,/icons/,/icons/bk2site/,' ${WRKSRC}/*
	@${PERL} -pi -e 's,long int l,time_t l,' ${WRKSRC}/reference.C

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${PREFIX}/${ICONSDIR}
	${MKDIR} ${PREFIX}/${CGIDIR}
	${CP} ${WRKSRC}/*.html ${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/*.gif ${PREFIX}/${ICONSDIR}
	${CP} ${WRKSRC}/*.pl ${PREFIX}/${CGIDIR}
	${CHMOD} +x ${PREFIX}/${CGIDIR}/*.pl
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
