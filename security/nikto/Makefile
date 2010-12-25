# New ports collection makefile for: 	nikto
# Date created: 			23 September 2002
# Whom: 				pandzilla
#
# $FreeBSD$
#
# $Tecnik: ports/security/nikto/Makefile,v 1.7 2005/12/13 16:26:20 itetcu Exp $
#

PORTNAME=	nikto
PORTVERSION=	2.1.3
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/${PORTNAME}/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/${PORTNAME}/

MAINTAINER=	niels@FreeBSD.org
COMMENT=	Web and CGI vulnerability scanner with SSL support

MAN1=		nikto.1

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGES.txt LICENSE.txt nikto.dtd nikto_manual.html

OPTIONS+=	SSLEAY "Use NET::SSLeay for ssl scanning" on

.include <bsd.port.pre.mk>

.ifdef(WITH_SSLEAY)
RUN_DEPENDS+=	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/bin/perl|${PERL}|" \
		-e "s|/etc/nikto.conf|${PREFIX}/etc/nikto.conf|" ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee "s|# (EXECDIR=)/usr/local/nikto|\1${DATADIR}|g" \
		-e "s|# (PLUGINDIR=)/opt/nikto/plugins|\1${DATADIR}/plugins|g" \
		-e "s|# (TEMPLATEDIR=)/opt/nikto/templates|\1${DATADIR}/templates|g" \
		-e "s|# (DOCDIR=)/opt/nikto/docs|\1${DOCSDIR}|g" ${WRKSRC}/nikto.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	${INSTALL_DATA} ${WRKSRC}/nikto.conf ${PREFIX}/etc/nikto.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/nikto.1 ${PREFIX}/man/man1/
	[ -f ${PREFIX}/etc/nikto.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/nikto.conf ${PREFIX}/etc/nikto.conf

	( cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} .  ${DATADIR}/plugins )
	( cd ${WRKSRC}/templates && ${COPYTREE_SHARE} .  ${DATADIR}/templates )
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.	endfor
.endif

.include <bsd.port.post.mk>
