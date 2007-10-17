# New ports collection makefile for:	audit
# Date created:				24 March 2002
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	audit
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www1.corest.com/download/audit/ \
		http://www2.corest.com/download/audit/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}beta-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for remote and centralized audit data collection

OPTIONS=	MYSQL "With MySQL support" off \
		PGSQL "With PostGreSQL support" off

MAKE_ARGS=	CFLAGS+="-fPIC -DPIC"

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}beta

USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-audit-libdir=${PREFIX}/lib/alat
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql \
			--with-mysql-incdir=${LOCALBASE}/include
PLIST_SUB+=	MYSQL=''
.else
PLIST_SUB+=	MYSQL='@comment '
.endif
.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql \
			--with-pgsql-libdir=${LOCALBASE}/lib \
			--with-pgsql-incdir=${LOCALBASE}/include
PLIST_SUB+=	PGSQL=''
.else
PLIST_SUB+=	PGSQL='@comment '
.endif
MANCOMPRESSED=	yes
MAN1=	audit.1
MAN8=	auditd.8

PORTDOCS=	COPYING README TODO
FIXPREFIX_CONF=	src/include/audconf.h src/auditd/auditd.8
LIBVERSION=	1

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s@Linux@FreeBSD@g" ${WRKSRC}/configure
	(${FIND} ${WRKSRC}/src/modules -name Makefile.in -exec \
		${REINPLACE_CMD} -e \
		"s!^LIB=\(.*\).{VERSION}!LIB=\1${LIBVERSION}!" {} \;)
	${REINPLACE_CMD} -e "s@AUDIT_VERSION@\"${LIBVERSION}\"@g" \
		${WRKSRC}/src/lib/modules.c
.for f in ${FIXPREFIX_CONF}
	${REINPLACE_CMD} -e "s@/etc/auditd.conf@${PREFIX}/etc/auditd.conf@g" \
		${WRKSRC}/${f}
.endfor

post-install:
	${INSTALL_DATA}	${WRKSRC}/auditd.conf ${PREFIX}/etc/auditd.conf.sample
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
