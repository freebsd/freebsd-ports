alter table dspam_stats add spam_learned int;
alter table dspam_stats add innocent_learned int;
alter table dspam_stats add spam_classified int;
alter table dspam_stats add innocent_classified int;
update dspam_stats set spam_learned = total_spam;
update dspam_stats set innocent_learned = total_innocent;
update dspam_stats set spam_classified = 0, innocent_classified = 0;
alter table dspam_stats drop column total_spam;
alter table dspam_stats drop column total_innocent;
alter table dspam_stats add spam_misclassified int;
alter table dspam_stats add innocent_misclassified int;
update dspam_stats set spam_misclassified = spam_misses;
update dspam_stats set innocent_misclassified = false_positives;
alter table dspam_stats drop column spam_misses;
alter table dspam_stats drop column false_positives;

