PORTNAME=	filelock
DISTVERSION=	4.2.4
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Platform independent file lock
WWW=		https://github.com/tox-dev/py-filelock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.29:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.5:devel/py-hatch-vcs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-cover>=10.2:devel/py-diff-cover@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.15.1:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.16:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=21.2:devel/py-virtualenv@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest
USE_GITHUB=	yes
GH_ACCOUNT=	tox-dev
GH_PROJECT=	filelock

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_cov \
		-p pytest_mock \
		-p pytest_randomly \
		-p pytest_timeout \
		--no-cov \
		-W ignore::pytest_benchmark.logger.PytestBenchmarkWarning \
		-W ignore::pytest_cov.CovDisabledWarning

NO_ARCH=	yes

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

# 111 tests fail w/out being disabled, see https://github.com/tox-dev/filelock/issues/864
PYTEST_BROKEN_TESTS=	test_async_expired_lock_is_broken \
			test_async_reads_giving_up_behind_a_writer_leave_nothing_behind \
			test_break_lock_file_break_name_is_unguessable \
			test_break_lock_file_unlinks_a_dead_holders_marker \
			test_executor_acquire_keeps_filesystem_calls_off_the_loop \
			test_expired_lock_becomes_acquirable \
			test_expired_soft_lock_is_broken \
			test_failed_acquire_spares_a_file_that_replaced_its_placeholder \
			test_failed_acquire_spares_a_successor_on_the_freed_inode_number \
			test_fifo_lock_file_with_attached_writer_self_heals \
			test_final_symlink_backend_refuses_to_lock \
			test_heartbeat_reports_a_symlinked_tree_as_lost \
			test_heartbeat_with_the_tree_swapped_for_a_symlink_is_lost \
			test_lazy_import_skips_asyncio_and_sqlite3 \
			test_lease_ages_out_a_malformed_record \
			test_lease_heartbeat_reports_an_owner_changed_that_persists \
			test_lease_heartbeat_tolerates_one_refresh_under_a_peers_exchange \
			test_lease_peer_takes_an_expired_claim \
			test_lease_reclaims_a_dead_same_host_holder \
			test_lease_self_heals_a_malformed_marker \
			test_lease_supersedes_a_live_holder_once_its_claim_ages_out \
			test_lease_takes_over_a_dead_owners_marker_with_its_own_lease_record \
			test_marker_lock_reclaims_dead_owner \
			test_marker_lock_reclaims_malformed_record \
			test_out_of_range_pid_self_heals_when_old \
			test_owner_is_stale_live_process_matching_token_held \
			test_owner_is_stale_live_process_mismatched_token_reclaimed \
			test_process_start_token_is_int_for_self \
			test_protocol_tree_swapped_after_an_acquire_is_refused \
			test_read_write_lock_connects_through_the_descriptor_when_linking_fails \
			test_read_write_lock_keeps_its_probe_descriptor_while_held \
			test_read_write_locks_held_together_each_keep_their_own_probe \
			test_release_under_a_peers_exchange_leaves_no_marker_naming_this_process \
			test_release_under_a_peers_exchange_leaves_the_peers_marker \
			test_remove_own_file_placeholder_names_this_process \
			test_socket_lock_file_self_heals \
			test_stale_break_after_a_breaker_was_killed_keeps_the_holder_alone \
			test_stale_break_claim_is_registered_before_it_is_visible \
			test_stale_break_evicts_a_placeholder_that_names_no_breaker \
			test_stale_break_finishes_a_claim_an_unreadable_record_interrupted \
			test_stale_break_keeps_the_lock_when_a_peer_swaps_its_marker_aside \
			test_stale_break_reclaims_a_marker_it_cannot_pin \
			test_stale_break_reclaims_a_record_a_dead_recoverer_claimed \
			test_stale_break_releases_the_registration_when_recovery_is_interrupted \
			test_stale_break_removes_a_stale_marker_a_dead_breaker_left_under_its_break_name \
			test_stale_break_restores_a_live_marker_a_dead_breaker_left_under_its_break_name \
			test_stale_break_restores_a_marker_a_dead_breaker_left_beside_its_placeholder \
			test_stale_break_restores_a_marker_of_an_unknown_contract_under_its_break_name \
			test_stale_break_restores_a_marker_of_another_host_with_the_breakers_pid \
			test_stale_break_restores_a_stranded_empty_marker \
			test_stale_break_restores_a_strict_sentinel_a_dead_breaker_left_under_its_break_name \
			test_stale_break_restores_under_an_exclusive_claim \
			test_stale_break_retries_a_claim_whose_return_failed \
			test_stale_break_takes_the_lock_over_in_one_poll \
			test_stale_break_undoes_an_exchange_that_took_a_peers_marker \
			test_stale_break_waits_for_a_claim_another_thread_is_working \
			test_stale_break_waits_when_a_peer_claimed_the_record_first \
			test_stale_lock_broken_when_process_dead \
			test_stale_take_over_interrupted_before_the_check_puts_the_marker_back \
			test_stale_take_over_keeps_the_lock_when_a_rename_replaces_its_marker \
			test_unparseable_lock_evicted_when_old

# tests as of 4.2.2: 2661 passed, 173 skipped, 108 deselected in 555.29s

.include <bsd.port.mk>
