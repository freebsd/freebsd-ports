# New ports collection makefile for:	popfile
# Date created:		22 Feb 2004
# Whom:			matusita@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	popfile
PORTVERSION=	0.20.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}:sf \
		${MASTER_SITE_SOURCEFORGE_JP}:sfjp
MASTER_SITE_SUBDIR=	${PORTNAME}/:sf ${PORTNAME}/6747/:sfjp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf \
		${PORTNAME}_jpn.zip:sfjp
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://home.jp.FreeBSD.org/~matusita/distfiles/
PATCHFILES=	popfile-0.20.0rc5-apop.patch

MAINTAINER=	matusita@FreeBSD.org
COMMENT=Automatic mail classification tool, acts as a POP3 proxy

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes

USE_ZIP=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.if defined(WITH_JAPANESE)
RUN_DEPENDS+=	${SITE_PERL}/jcode.pl:${PORTSDIR}/japanese/p5-jcode.pl
PATCHFILES+=	popfile-0.20.1-use-jcode.pl.patch
.endif
.endif

post-extract:
	${INSTALL_SCRIPT} ${FILESDIR}/setup-popfile.sh ${WRKSRC}
	${CP} ${WRKDIR}/0_20_1_1/POPFile/0.20.1/Classifier/Bayes.pm \
						${WRKSRC}/Classifier/Bayes.pm

post-patch:
	${REINPLACE_CMD} -e "s|__DATADIR__|${DATADIR}|" \
						${WRKSRC}/setup-popfile.sh
	${RM} -f ${WRKSRC}/setup-popfile.sh.bak
	${CHMOD} +x ${WRKSRC}/popfile.pl
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}

.include <bsd.port.post.mk>
