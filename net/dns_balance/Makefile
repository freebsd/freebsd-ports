# Ports collection makefile for:	DNS Balance
# Date created:			5 March 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dns_balance
PORTVERSION=	0.6.1
CATEGORIES=	net
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/
DISTNAME=	DNS-Balance-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/dns_balance.rb \
			${WRKSRC}/sample/makedb.rb \
			${WRKSRC}/sample/makeringdb.rb \
			${WRKSRC}/sample/make_namespace.rb
ETCS=		addrdb.rb \
		namespace.rb
LIBS=		datatype.rb \
		log_writer.rb \
		util.rb
EXAMPLES_EXEC=	make_namespace.rb \
		makedb.rb \
		makeringdb.rb \
		ringupdate.sh
EXAMPLES_DATA=	addr \
		addr.ring \
		addr.ring.txt \
		addr.txt \
		namespace.txt
DOCS_EN=	Q_and_A.dns_balance.eng \
		README.dns_balance.eng \
		README.dnsbalance+daemontools.eng
DOCS_JA=	ChangeLog \
		Q_and_A.dns_balance \
		README.dns_balance \
		README.dnsbalance+daemontools

post-patch:
	${RUBY} -pe 'gsub /!!PREFIX!!/, "${PREFIX}"' ${WRKSRC}/dns_balance.rb > ${WRKSRC}/dns_balance
	${RUBY} -pe 'gsub /!!PREFIX!!/, "${PREFIX}"' ${FILESDIR}/dns_balance.sh > ${WRKSRC}/dns_balance.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for f in ${ETCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}/${f}-dist
	[ ! -f ${PREFIX}/etc/${PORTNAME}/${f} ] && ${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${PORTNAME}/${f}
.endfor
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for f in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/${PORTNAME}/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/dns_balance.sh ${PREFIX}/etc/rc.d/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for f in ${EXAMPLES_EXEC}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/${PORTNAME}/
.endfor
.for f in ${EXAMPLES_DATA}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/${PORTNAME}/
.endfor
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
