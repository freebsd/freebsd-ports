# New ports collection makefile for:	apachetop
# Date created:				30 Sep 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	apachetop
PORTVERSION=	0.12.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.webta.org/apachetop/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache RealTime log stats

MAKE_JOBS_SAFE=  yes

GNU_CONFIGURE=	yes

MAN1=		apachetop.1
PLIST_FILES=	bin/apachetop

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
	@cd ${WRKSRC} && ${TOUCH} -r configure.ac aclocal.m4 stamp-h.in

.include <bsd.port.post.mk>
