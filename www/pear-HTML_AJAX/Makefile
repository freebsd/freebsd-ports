# Ports collection makefile for:  pear-HTML_AJAX
# Date created:			  20 October 2006
# Whom:				  Simun Mikecin <numisemis at yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	HTML_AJAX
PORTVERSION=	0.5.6
CATEGORIES=	www devel pear

MAINTAINER=	numisemis@yahoo.com
COMMENT=	PHP and JavaScript AJAX library

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		AJAX.php AJAX/Action.php AJAX/Debug.php AJAX/Helper.php \
		AJAX/JSON.php AJAX/Response.php AJAX/Server.php \
		AJAX/Serializer/JSON.php AJAX/Serializer/Null.php \
		AJAX/Serializer/PHP.php AJAX/Serializer/Urlencoded.php \
		AJAX/Serializer/Error.php AJAX/Serializer/XML.php
EXAMPLES=	guestbook/auto_server.php \
		guestbook/guestbook.class.php \
		guestbook/index.php \
		login/php/auto_server.php \
		login/php/class.login.php \
		login/index.php \
		login/login.css \
		review/auto_server.php \
		review/index.php \
		review/review.class.php \
		support/customLib.js \
		support/interceptor.php \
		support/isajax.php \
		support/livesearch.class.php \
		support/post_tester.php \
		support/test.class.php \
		support/test.xml \
		support/test2.class.php \
		support/testHaa.class.php \
		support/xml.class.php \
		tests/behaviorSpeed.php \
		tests/duplicateJSLib.php \
		tests/helper_combine.php \
		tests/js_utils_getElements.php \
		tests/js_utils_vardump.php \
		tests/serialize.php.examples.php \
		tests/serialize.url.examples.php \
		tests/setInnerHTML.js \
		tests/setInnerHTML.php \
		tests/test_behavior.html \
		tests/test_priority.php \
		tests/test_speed.php \
		action_usage.php \
		auto_server.php \
		bugfixes.php \
		error_usage.php \
		form.php \
		grab.php \
		haa_usage.php \
		helper_usage.php \
		index.php \
		interceptors.php \
		interceptorServer.php \
		php_callback.php \
		proxyless_usage.php \
		proxy_usage_inline_javascript.php \
		proxy_usage_server.php \
		queue_usage.php \
		README \
		server.php \
		shoutbox.php \
		slow_livesearch.php \
		slow_server.php \
		xmlserver.php \
		xml_usage.php
_EXAMPLESDIR=	examples

DATA=		Alias.js IframeXHR.js clientPool.js \
		Compat.js Loading.js dhtmlHistory.js \
		Dispatcher.js Main.js HTML_AJAX.js \
		Queue.js util.js HTML_AJAX_lite.js \
		Request.js HttpClient.js \
		behavior/behavior.js behavior/cssQuery-p.js \
		serializer/JSON.js serializer/haSerializer.js\
		serializer/UrlSerializer.js serializer/phpSerializer.js

_DATADIR=	js

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
