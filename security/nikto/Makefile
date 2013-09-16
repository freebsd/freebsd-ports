# Created by: pandzilla
# $FreeBSD$

PORTNAME=	nikto
PORTVERSION=	2.1.5
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.cirt.net/${PORTNAME}/ \
		http://www.mirrors.wiretapped.net/security/vulnerability-assessment/${PORTNAME}/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Web and CGI vulnerability scanner with SSL support

LICENSE=	GPLv2

OPTIONS_DEFINE=	SSLEAY DOCS
OPTIONS_DEFAULT=SSLEAY
SSLEAY_DESC=	Use NET::SSLeay for ssl scanning

NO_BUILD=	yes

USE_BZIP2=	yes
USES=		perl5
USE_PERL5=	run

MAN1=		nikto.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSLEAY}
RUN_DEPENDS+=	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}| ; \
		 s|/etc/nikto.conf|${PREFIX}/etc/nikto.conf|' ${WRKSRC}/nikto.pl
	@${REINPLACE_CMD} -Ee \
		's|# (EXECDIR=).*/nikto|\1${DATADIR}| ; \
		 s|# (DBDIR=).*/databases|\1${DATADIR}/databases| ; \
		 s|# (PLUGINDIR=).*/plugins|\1${DATADIR}/plugins| ; \
		 s|# (TEMPLATEDIR=).*/templates|\1${DATADIR}/templates| ; \
		 s|# (DOCDIR=).*/docs|\1${DOCSDIR}|' ${WRKSRC}/nikto.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nikto.pl ${PREFIX}/bin/nikto
	${INSTALL_MAN} ${WRKSRC}/docs/nikto.1 ${PREFIX}/man/man1/nikto.1
	${INSTALL_DATA} ${WRKSRC}/nikto.conf ${PREFIX}/etc/nikto.conf.sample
.if !exists(${PREFIX}/etc/nikto.conf)
	(cd ${PREFIX}/etc && ${CP} -p nikto.conf.sample nikto.conf)
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/replay.pl ${DATADIR}
.for i in databases plugins templates
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${DATADIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES.txt LICENSE.txt nikto.dtd nikto_manual.html
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
