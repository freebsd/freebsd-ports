# New ports collection makefile for:   htdig
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	htdig
PORTVERSION=	3.2.0.b6
PORTREVISION=	3
CATEGORIES=	textproc www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/3.2.0b6
DISTNAME=	htdig-3.2.0b6

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	A www indexing and searching system

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config-dir=${PREFIX}/etc/htdig \
		--with-default-config-file=${PREFIX}/etc/htdig/htdig.conf \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-database-dir=${PREFIX}/share/htdig/database \
		--with-cgi-bin-dir=${PREFIX}/www/cgi-bin \
		--with-search-dir=${PREFIX}/www/data \
		--with-image-dir=${PREFIX}/www/icons/htdig \
		--with-image-url-prefix=/icons/htdig \
		--with-ssl

MAN1=		htdig.1 htdig-pdfparser.1 htdump.1 htfuzzy.1 htload.1 \
		htmerge.1 htnotify.1 htpurge.1 htsearch.1 htstat.1 rundig.1

MAN8=		htdigconfig.8

OPTIONS=	APACHE "Include ${APACHE_PORT} as a dependency" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	1.3+
CONFIGURE_ARGS+=	--with-apache=${LOCALBASE}/sbin
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.  if ${APACHE_VERSION} > 13
PLIST_DIRSTRY+=	www/cgi-bin www/data www/icons
.  endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

pre-install:
.if exists(${PREFIX}/etc/htdig/htdig.conf)
	${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.old
.endif

post-install:
	@${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.sample
.if exists(${PREFIX}/etc/htdig/htdig.conf.old)
	${MV} ${PREFIX}/etc/htdig/htdig.conf.old ${PREFIX}/etc/htdig/htdig.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for f in ChangeLog ChangeLog.0 README STATUS
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.for f in *.html *.gif
	@${INSTALL_DATA} ${WRKSRC}/htdoc/${f} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.post.mk>
