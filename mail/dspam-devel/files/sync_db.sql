
update dspam_stats set spam_misclassified = spam_misses;
update dspam_stats set innocent_misclassified = false_positives;
