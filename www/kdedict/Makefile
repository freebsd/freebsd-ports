# New ports collection makefile for:	www/kdedict
# Date created:				2005-12-16
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Tecnik: ports/www/kdedict/Makefile,v 1.3 2006/01/30 19:27:22 itetcu Exp $
#

PORTNAME=	kdedict
PORTVERSION=	20030925
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.i18n.kde.org/tools/${PORTNAME}/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Web based db to administer standard translations of a translation team

RUN_DEPENDS=	p5-Date-Manip>0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-SQL-Statement>0:${PORTSDIR}/databases/p5-SQL-Statement \
		p5-Text-CSV_XS>0:${PORTSDIR}/textproc/p5-Text-CSV_XS

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_APACHE=	yes

CGI_DIR?=	${PREFIX}/www/cgi-bin
SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME} CGI_DIR=${CGI_DIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL}<500800
RUN_DEPENDS+=	p5-DBD-File>0:${PORTSDIR}/databases/p5-DBD-File
.endif

pre-everything::
	@${ECHO_CMD} "Define to suit your needs:"
	@${ECHO_CMD} "CGI_DIR (default: ${PREFIX}/www/cgi-bin)"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" \
		${WRKSRC}/${PORTNAME}.cgi

do-install:
	@${MKDIR} ${CGI_DIR}/kdedictionary
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${CGI_DIR}/kdedictionary
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} -o ${WWWOWN} -g ${WWWGRP} ${PORTNAME}.cgi ${CGI_DIR} && \
	${INSTALL}  -o ${WWWOWN} -g ${WWWGRP} -m 0644 kdedictionary/* ${CGI_DIR}/kdedictionary

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
