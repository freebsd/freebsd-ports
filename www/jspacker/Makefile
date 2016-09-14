# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jspacker
DISTVERSION=	1.00b
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://nivi.interfree.it/distfiles/${PORTNAME}/ \
		http://deanedwards.googlecode.com/svn/trunk/download/
DISTNAME=	packer2.perl

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	JavaScript compressor/obfuscator (Perl version)

BROKEN=		Unfetchable (google code has gone away)

JSPACKER=	jsPacker.pl

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

USES=		perl5 shebangfix zip
USE_PERL5=	run
SHEBANG_FILES=	jsPacker.pl
perl_OLD_CMD=	perl

SUB_FILES=	${PORTNAME}
SUB_LIST=	JSPACKER=${JSPACKER} \
		PERL5=${PERL}

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR} && \
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.pm ${STAGEDIR}${DATADIR} && \
	${INSTALL_SCRIPT} ${JSPACKER} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.htm ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
