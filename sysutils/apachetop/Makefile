# New ports collection makefile for:	apachetop
# Date created:				30 Sep 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	apachetop
PORTVERSION=	0.12
CATEGORIES=	sysutils
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Apache RealTime log stats

WANT_AUTOCONF_VER=259
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		apachetop.1
PLIST_FILES=	sbin/apachetop

OPTIONS=	ADNS "Asynchronous-capable DNS support" off \
		FAM "File Alteration Monitor support" off \
		PCRE "Perl Compatible Regular Expressions support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ADNS)
LIB_DEPENDS+=	adns.1:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=--with-adns=${LOCALBASE}
.endif

.if defined(WITH_FAM)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
CONFIGURE_ARGS+=--with-fam=${LOCALBASE}
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's,struct (circle_struct),\1,g' \
		${WRKSRC}/src/hits_circle.*
	@${REINPLACE_CMD} -E -e 's,enum (adns_queryflags),\1,g' \
		${WRKSRC}/src/log.*
	@${REINPLACE_CMD} -e 's,@AUTOCONF@,${AUTOCONF},' \
		-e 's,@AUTOHEADER@,${AUTOHEADER},' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
